/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 06:03:48 by gsimeon           #+#    #+#             */
/*   Updated: 2019/07/15 22:44:28 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** Usage :
** call it like this everywere
** return(ui_error(<YOUR_ERROR_CODE>, __FILE__, __LINE__));
**
** Code Explained :
**  SDL_GetError retrieve a message about error inside SDL
*/

int	ui_error(Uint32 error, const char *file, const char *func, const int line)
{
	const char	*geterror;

	geterror = SDL_GetError();
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"%s() called from \033[31m\"\
\033[33m%s()\033[31m:\
:\033[34m./%s\033[31m:\
:\033[33m%d\033[31m\
\"\033[0m\n",
		__func__, func, file, line);
	if (geterror != NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL say : %s", geterror);
		SDL_ClearError();
	}
	return (ui_exit(error));
}
