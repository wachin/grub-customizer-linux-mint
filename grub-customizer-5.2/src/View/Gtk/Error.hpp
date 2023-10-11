/*
 * Copyright (C) 2010-2011 Daniel Richter <danielrichter2007@web.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * 
 * Additional permission under GNU GPL version 3 section 7
 *
 * If you modify this program, or any covered work, by linking or combining
 * it with the OpenSSL library (or a modified version of that library),
 * containing parts covered by the terms of the OpenSSL license, the licensors
 * of this program grant you additional permission to convey the resulting work.
 * Corresponding source for a non-source form of such a combination shall include
 * the source code for the parts of the OpenSSL library used as well as that of
 * the covered work.
 */
#ifndef ERRORGTK_H_
#define ERRORGTK_H_
#include "../Error.hpp"

#include <gtkmm.h>
#include <libintl.h>

class View_Gtk_Error :
	public View_Error
{
	void showErrorMessage(std::string const& errorMessage, bool allowContinue)
	{
		Gtk::MessageDialog msgDlg(gettext("An error occurred"), false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_NONE, true);
		msgDlg.set_secondary_text(gettext("please Inform the author about this problem. The following information could be helpful:") + std::string("\n\n") + errorMessage);
		msgDlg.set_title(gettext("An error occurred"));
		msgDlg.add_button(Gtk::Stock::QUIT, Gtk::RESPONSE_CLOSE);
		if (allowContinue) {
			msgDlg.add_button(gettext("continue (risk data loss)"), Gtk::RESPONSE_CANCEL);
		}
		if (msgDlg.run() == Gtk::RESPONSE_CLOSE) {
			this->onQuitClick();
		}
	}
};


#endif /* ERRORGTK_H_ */
