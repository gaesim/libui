/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_modal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <aberrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:46:58 by aberrahm          #+#    #+#             */
/*   Updated: 2020/02/15 18:41:26 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    ui_modal(int buttons, char** names, char* header, char* contents)
{
    if (ui_modal != 0)
		return(ui_error(1, __FILE__, __func__, __LINE__));
}