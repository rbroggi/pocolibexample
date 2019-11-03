//
// Created by rbroggi on 11/3/19.
//

#include <iostream>
#include <Poco/HexBinaryDecoder.h>
#include <Poco/HexBinaryEncoder.h>
#include <Poco/Base64Encoder.h>
#include <Poco/Base64Decoder.h>
#include <Poco/Crypto/RSADigestEngine.h>
#include <HexAndBase64Utils.h>

namespace pocolib_ex {

std::string fromFormatToFormat(usecase::Format source_format, usecase::Format target_format, const std::string &content) {
  if (source_format == usecase::Format::BIN && target_format == usecase::Format::HEX) {
    return toHex(content);
  } else if (source_format == usecase::Format::BIN && target_format == usecase::Format::BASE_64) {
    return toBase64(content);
  } else if (source_format == usecase::Format::HEX && target_format == usecase::Format::BIN) {
    return fromHex(content);
  } else if (source_format == usecase::Format::HEX && target_format == usecase::Format::BASE_64) {
    return toBase64(fromHex(content));
  } else if (source_format == usecase::Format::BASE_64 && target_format == usecase::Format::BIN) {
    return fromBase64(content);
  } else if (source_format == usecase::Format::BASE_64 && target_format == usecase::Format::HEX) {
    return toHex(fromBase64(content));
  }
  return content;
}

std::string toBase64(const std::string &input) {
  std::istringstream in(input);
  std::ostringstream out;
  Poco::Base64Encoder b64out(out);
  std::copy(std::istreambuf_iterator<char>(in),
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(b64out));
  b64out.close();
  return out.str();
}

std::string fromBase64(const std::string &input) {
  std::istringstream in(input);
  std::ostringstream out;
  Poco::Base64Decoder b64in(in);

  std::copy(std::istreambuf_iterator<char>(b64in),
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(out));
  return out.str();
}

std::string toHex(const std::string &input) {
  std::istringstream in(input);
  std::ostringstream out;
  Poco::HexBinaryEncoder b64out(out);
  std::copy(std::istreambuf_iterator<char>(in),
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(b64out));
  b64out.close();
  return out.str();
}

std::string fromHex(const std::string &input) {
  std::istringstream in(input);
  std::ostringstream out;
  Poco::HexBinaryDecoder b64in(in);

  std::copy(std::istreambuf_iterator<char>(b64in),
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(out));
  return out.str();
}

}