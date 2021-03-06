/*
 * rfcc1101 - SPI Protocol Driver for TI CC1101 RF communication module.
 *
 * Copyright (C) 2013 Wolfgang Klenk <wolfgang.klenk@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROTOCOL_HPP_
#define PROTOCOL_HPP_

/**
 * A protocol is used to receive or transmit a message.
 * It can make use of different strategies WHEN and HOW to read the data
 * from the CC1101's FIFO buffer.
 */
class Protocol {

public:
	virtual ~Protocol() {};

	/**
	 * Note: RSSI and LQI are appended to the end of the message.
	 */
	virtual int receive(uint8_t buffer[], size_t& nbytes) = 0;

	virtual int transmit(const uint8_t buffer[], size_t nbytes) = 0;
};


#endif /* PROTOCOL_HPP_ */
