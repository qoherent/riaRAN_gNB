import logging
import os
from collections import defaultdict
from contextlib import contextmanager, suppress
from pprint import pformat

import grpc
from pytest_html import extras
from retina.protocol.base_pb2 import Empty


@contextmanager
def get_ue_gnb_epc(self, extra, band, common_scs, bandwidth):
    """
    Get test elements
    """
    try:
        test_config = {
            "ue": {
                "parameters": {
                    "band": band,
                    "dl_arfcn": get_dl_arfcn(band),
                    "ssb_arfcn": get_ssb_arfcn(band, bandwidth),
                    "common_scs": common_scs,
                    "ssb_scs": common_scs,
                    "bandwidth": bandwidth,
                    "log_level": get_loglevel(),
                }
            },
            "gnb": {
                "parameters": {
                    "band": band,
                    "dl_arfcn": get_dl_arfcn(band),
                    "common_scs": common_scs,
                    "bandwidth": bandwidth,
                    "log_level": get_loglevel(),
                }
            },
        }
        logging.info("Test config: \n%s", pformat(test_config))
        self.test_config = test_config
        self.retina_manager.parse_configuration(test_config)

        # Get clients
        ue = self.retina_manager.get_ue()
        gnb = self.retina_manager.get_gnb()
        epc = self.retina_manager.get_epc()

        yield ue, gnb, epc

    except Exception as err:
        raise err from None

    finally:

        teardown_ok = True

        with suppress(UnboundLocalError, NameError):
            extra.append(extras.url(self.relative_output_html_path, name="[[ Go to logs and configs ]]"))

        with suppress(NameError, grpc._channel._InactiveRpcError):
            return_code = gnb.Stop(Empty()).value
            teardown_ok &= return_code == 0
            if return_code < 0:
                logging.error("GNB crashed with exit code %s", return_code)
            elif return_code > 0:
                logging.error("GNB has %d errors or warnings", return_code)
        with suppress(NameError, grpc._channel._InactiveRpcError):
            epc.Stop(Empty()).value
        with suppress(NameError, grpc._channel._InactiveRpcError):
            return_code = ue.Stop(Empty()).value
            teardown_ok &= return_code == 0
            if return_code < 0:
                logging.error("UE crashed with exit code %s", return_code)
            elif return_code > 0:
                logging.error("UE has %d errors or warnings", return_code)

        assert teardown_ok is True


def get_dl_arfcn(band):
    """
    Get dl arfcn
    """
    return {3: 368500, 7: 536020, 41: 520000}[band]


def get_ssb_arfcn(band, bandwidth):
    """
    Get SSB arfcn
    """
    return {
        3: defaultdict(
            lambda: 368410,
            {
                30: 367450,
                40: 366490,
                50: 365530,
            },
        ),
        7: defaultdict(
            lambda: 535930,
            {
                30: 534970,
                40: 534010,
                50: 533050,
            },
        ),
        41: defaultdict(lambda: 520090, {20: 519850}),
    }[band][bandwidth]


def get_loglevel():
    """
    Get retina loglevel
    """
    try:
        return os.environ["RETINA_LOGLEVEL"]
    except KeyError:
        return "info"
