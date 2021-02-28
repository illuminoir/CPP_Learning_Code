#pragma once

#include "line.hpp"

class LineSegment: public Line {
public:
	using Line::Line;

	std::ostream& print(std::ostream& os) const override {
		return os << "line_seg " << first << "--" << last;
	}

	~LineSegment() = default;
};
