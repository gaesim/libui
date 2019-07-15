/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 01:22:35 by gsimeon           #+#    #+#             */
/*   Updated: 2019/07/15 22:57:24 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "stdio.h"

int ui_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return(ui_error(1, __FILE__, __func__, __LINE__));
	return (0);
}
