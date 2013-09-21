/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2013 Colin Walters <walters@verbum.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"

#include <string.h>

/* This program exists to allow JS test scripts to log to journald.
 * Until structured logging is added to GLib.
 */
#include "libgsystem.h"

int
main (int argc, char **argv)
{
  GError *local_error = NULL;
  GError **error = &local_error;
  gs_free char *msgid = NULL;
  const char *eq;
  const char *msg;

  if (argc <= 1)
    {
      g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
		   "Usage: %s MESSAGEID=MESSAGE", argv[0]);
      goto out;
    }

  msg = argv[1];
  eq = strchr (msg, '=');
  g_assert (eq);
  msgid = g_strndup (msg, eq - msg);
  gs_log_structured_print_id_v (msgid, "%s", eq + 1);

 out:
  if (local_error)
    {
      g_printerr ("%s\n", local_error->message);
      g_clear_error (&local_error);
      return 1;
    }
  return 0;
}
