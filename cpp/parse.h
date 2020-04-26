#ifndef INCLUDED_PARSE_H
#define INCLUDED_PARSE_H

#include <string>
#include <memory>
#include "events/event.h"

std::shared_ptr<Event> parse(const std::string& s);

#endif

