/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2017 Frank Stettner <frank-stettner@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DATA_SIGNALDATA_HPP
#define DATA_SIGNALDATA_HPP

#include <cstdint>
#include <memory>
#include <vector>

#include <QObject>

using std::shared_ptr;
using std::vector;

namespace sv {
namespace data {

class Segment;

class SignalData : public QObject
{
	Q_OBJECT

public:
	SignalData() = default;
	virtual ~SignalData() = default;

public:
	virtual void clear() = 0;

	virtual size_t get_sample_count() const = 0;
	virtual void push_sample(void *sample) = 0;
};

} // namespace data
} // namespace sv

#endif // DATA_SIGNALDATA_HPP
