/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 06:03:48 by gsimeon           #+#    #+#             */
/*   Updated: 2019/01/31 07:12:43 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
**
** Usage :
** call it like this everywere
** return(ui_error(<YOUR_ERROR_CODE>, __FILE__, __LINE__));
**
*/

int ui_error(Uint32 error, char *file, int line)
{
	const char	*geterror;

	geterror = SDL_GetError();
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ui_error called at <\033[31m%s\033[0m::\033[31m%d\033[0m>\n", file, line);
	if (geterror != NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL say : %s", geterror);
		SDL_ClearError();
	}
	return (ui_exit(error));
}
