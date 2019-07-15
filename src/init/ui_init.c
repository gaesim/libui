/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 01:22:35 by gsimeon           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/05 19:04:20 by aberrahm         ###   ########.fr       */
=======
/*   Updated: 2019/07/15 22:57:24 by gsimeon          ###   ########.fr       */
>>>>>>> fac9d67e24e2ef47a21ef1074e004069b79f7d43
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
// #include "stdio.h"

int ui_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return(ui_error(1, __FILE__, __func__, __LINE__));
	return (0);
}
