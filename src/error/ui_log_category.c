/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_log_category.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:34:20 by gsimeon           #+#    #+#             */
/*   Updated: 2020/02/22 20:08:03 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** Usage :
**	for retrieve category
**		ui_log_category(-1);
**	for set category
**		ui_log_category(SDL_LOG_CATEGORY_<category needed>);
**
** Note:
**	Default SDL settings are : 
**	  Priority Order [1..6]	:
**		VERBOSE
**		DEBUG
**		INFO
**		WARN
**		ERROR
**		CRITICAL
**	  Category Order [0..8] :
**		APPLICATION  [INFO]
**		ERROR        [CRITICAL]
**		ASSERT       [WARN]
**		SYSTEM       [CRITICAL]
**		AUDIO        [CRITICAL]
**		VIDEO        [CRITICAL]
**		RENDER       [CRITICAL]
**		INPUT        [CRITICAL]
**		TEST         [VERBOSE]
**	
** Code Explained :
** 	all SDL_log need a log category, they call ui_log_category for retrieve it
**	It can be change at any time
*/

int		ui_log_category(int new_category)
{
	static int category;

	if (new_category >= 0)
		category = new_category;
	return category;
}