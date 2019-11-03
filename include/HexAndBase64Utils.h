//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include <string>
#include <usecase/Format.h>

namespace pocolib_ex {

std::string fromFormatToFormat(usecase::Format source_format, usecase::Format target_format, const std::string& content);

std::string toBase64(const std::string& input);

std::string fromBase64(const std::string &input);

std::string toHex(const std::string &input);

std::string fromHex(const std::string &input);

}
