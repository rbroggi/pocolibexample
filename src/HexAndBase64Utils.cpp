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

std::string toBase64(const std::string &input) {
  std::istringstream in(input);
  std::ostringstream out;
  Poco::Base64Encoder b64out(out);
  std::copy(std::istreambuf_iterator< char >(in),
            std::istreambuf_iterator< char >(),
            std::ostreambuf_iterator< char >(b64out));
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