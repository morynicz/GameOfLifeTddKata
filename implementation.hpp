#pragma once
#include <list>

using Board = std::list<bool>;

Board calculateNextGeneration(const Board&);