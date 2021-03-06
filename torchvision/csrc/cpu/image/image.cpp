
#include "image.h"
#include <ATen/ATen.h>
#include <Python.h>

// If we are in a Windows environment, we need to define
// initialization functions for the _custom_ops extension
#ifdef _WIN32
PyMODINIT_FUNC PyInit_image(void) {
  // No need to do anything.
  return NULL;
}
#endif

static auto registry = torch::RegisterOperators()
                           .op("image::decode_png", &decodePNG)
                           .op("image::encode_png", &encodePNG)
                           .op("image::write_png", &writePNG)
                           .op("image::decode_jpeg", &decodeJPEG)
                           .op("image::encode_jpeg", &encodeJPEG)
                           .op("image::write_jpeg", &writeJPEG)
                           .op("image::decode_image", &decode_image);
