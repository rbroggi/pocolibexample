//
// Created by rbroggi on 11/3/19.
//

#include "UsecaseFactory.h"
#include "Decrypt.h"
#include "Encrypt.h"
#include "Hash.h"
#include "Sign.h"
#include "Verify.h"
#include <algorithm>
#include <fstream>
#include <iostream>

namespace pocolib_ex {
namespace usecase {

using namespace std::string_literals;

std::tuple<bool, std::unique_ptr<UseCase>, std::string> UsecaseFactory::retrieveUseCase(int argc, char **argv) {
  static std::array<std::string, 5> possibleCases = {"hash"s, "enc"s, "dec"s, "sign"s, "verify"s};

  if (argc > 2) {
    auto u_case_it = std::find(possibleCases.cbegin(), possibleCases.cend(), std::string{argv[1]});
    if (u_case_it != possibleCases.end()) {
      if ((*u_case_it) == "hash"s && argc == 5 && isValidHash(argv[2]) &&
          retrieveFormat(argv[3]) != Format::NONE) {
        return {true, std::make_unique<Hash>(argv[2], retrieveFormat(argv[3])),
                std::string{argv[4]}};
      }

      if ((*u_case_it) == "enc"s && argc == 5 && fileExist(argv[2]) &&
          retrieveFormat(argv[3]) != Format::NONE) {
        return {true,
                std::make_unique<Encrypt>(argv[2], retrieveFormat(argv[3])),
                std::string{argv[4]}};
      }

      if ((*u_case_it) == "dec"s && argc == 6 && fileExist(argv[2]) &&
          retrieveFormat(argv[4]) != Format::NONE) {
        return {true,
                std::make_unique<Decrypt>(argv[2], argv[3],retrieveFormat(argv[4])),
                std::string {argv[5]}};
      }

      if ((*u_case_it) == "sign"s && argc == 7 && fileExist(argv[3]) &&
          retrieveFormat(argv[5]) != Format::NONE) {
        return {true,
                std::make_unique<Sign>(argv[2], argv[3], argv[4], retrieveFormat(argv[5])),
                std::string {argv[6]}};
      }

      if ((*u_case_it) == "verify"s && argc == 7 && fileExist(argv[3]) &&
          retrieveFormat(argv[5]) != Format::NONE) {
        return {true,
                std::make_unique<Verify>(argv[2], argv[3], argv[4], retrieveFormat(argv[5])),
                std::string {argv[6]}};
      }
    }
  }

  std::cerr << "Wrong number of arguments.\n Usage:\n "
            << argv[0] << " enc <publicKeyPath> <bin/hex/b64> <content>\n"
            << argv[0] << " dec <privKeyPath> <pwd> <bin/hex/b64> <content>\n"
            << argv[0] << " sign <MD5/SHA1/SHA256/SHA512> <private_key_file> <pwd> <bin/hex/b64> <content>\n"
            << argv[0] << " verify <MD5/SHA1/SHA256/SHA512> <public_key_file_path> <signature> <signFormat:bin/hex/b64> <content>\n"
            << argv[0] << " hash <MD5/SHA1/SHA256/SHA512> <bin/hex/b64> <content>\n";
  return {false, nullptr, ""};
}

bool UsecaseFactory::isValidHash(const std::string& candidate) {
  static std::array<std::string, 4> possibleHashes = {"MD5"s, "SHA1"s, "SHA256"s, "SHA512"s};
  return std::find(possibleHashes.cbegin(), possibleHashes.cend(), candidate) != possibleHashes.cend();
}

Format UsecaseFactory::retrieveFormat(const std::string &format_str) {
  if (format_str == "bin"s) {
    return Format::BIN;
  } else if (format_str == "hex"s) {
    return Format::HEX;
  } else if (format_str == "b64"s) {
    return Format::BASE_64;
  }
  return Format::NONE;
}

bool UsecaseFactory::fileExist(const std::string &name) {
  std::ifstream f(name.c_str());
  return f.good();
}

}
}
