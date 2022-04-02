#include "../includes/MorseCodeDecipher.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace Morse;

PYBIND11_MODULE(morse, handle){
    handle.doc() = "Module for import c++";

    py::class_<Morse::MorseCodeDecipher>(
        handle, "PyMorseCodeDecipher"
    )
    .def(py::init<const char*>())
    .def(py::init<>())
    .def("ConvertToEnglish", &MorseCodeDecipher::ConvertToEnglish)
    .def("SetFilename", &MorseCodeDecipher::SetFilename)
    .def("Decipher", &MorseCodeDecipher::Decipher)
    .def("GetDecipheredCode", &MorseCodeDecipher::GetDecipheredCode)
    .def("SetPhrase", &MorseCodeDecipher::SetPhrase)
    .def("GetPhrase", &MorseCodeDecipher::GetPhrase)
    .def("GetFilename", &MorseCodeDecipher::GetFilename);

    py::class_<Morse::MorseCodePlayer>(
        handle, "PyMorseCodePlayer"
    )
    .def(py::init<const char*>())
    .def(py::init<>())
    .def("ConvertToMorse", &MorseCodePlayer::ConvertToMorse)
    .def("InitWAVE", &MorseCodePlayer::InitWAVE)
    .def("RecordMorse", &MorseCodePlayer::RecordMorse)
    .def("PlayMorse", &MorseCodePlayer::PlayMorse)
    .def("GetPhrase", &MorseCodePlayer::GetPhrase)
    .def("SetFilename", &MorseCodePlayer::SetFilename)
    .def("SetPhrase", &MorseCodePlayer::SetPhrase)
    .def("GetFilename", &MorseCodePlayer::GetFilename);
}

