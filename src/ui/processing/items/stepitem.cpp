/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2018 Frank Stettner <frank-stettner@gmx.net>
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

#include <QString>

#include "stepitem.hpp"
#include "src/processing/baseblock.hpp"

namespace sv {
namespace ui {
namespace processing {
namespace items {

StepItem::StepItem(
		QListWidget *parent) :
	QListWidgetItem(parent)
{
	//this->setText(QString("%1 (Step Sequence)").arg(block_->name()));
	this->setIcon(QIcon(":/icons/settings-views"));
}


void StepItem::set_block(shared_ptr<sv::processing::BaseBlock> block)
{
	block_ = block;
	this->setText(QString("%1 (Step Sequence)").arg(block_->name()));
}

} // namespace items
} // namespace processing
} // namespace ui
} // namespace sv