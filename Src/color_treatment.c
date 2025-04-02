/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:14:11 by alex              #+#    #+#             */
/*   Updated: 2025/04/02 06:36:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_from_palethe(int i, int max_i)
{
	int color_map[79];

	(color_map[0] = 0x36045d, color_map[1] = 0x420260);
	(color_map[2] = 0x4d0062, color_map[3] = 0x580064);
	(color_map[4] = 0x620066, color_map[5] = 0x6d0067);
	(color_map[6] = 0x770068, color_map[7] = 0x820068);
	(color_map[8] = 0x8c0068, color_map[9] = 0x960068);
	(color_map[10] = 0x9f0067, color_map[11] = 0xa90066);
	(color_map[12] = 0xb20065, color_map[13] = 0xba0063);
	(color_map[14] = 0xc30361, color_map[15] = 0xcb115f);
	(color_map[16] = 0xd31c5d, color_map[17] = 0xda255a);
	(color_map[18] = 0xe12f58, color_map[19] = 0xe83855);
	(color_map[20] = 0xee4151, color_map[21] = 0xf34a4e);
	(color_map[22] = 0xf9534a, color_map[23] = 0xfd5d46);
	(color_map[24] = 0xff6642, color_map[25] = 0xff6f3e);
	(color_map[26] = 0xff7939, color_map[27] = 0xff8336);
	(color_map[28] = 0xff8e37, color_map[29] = 0xff9838);
	(color_map[30] = 0xffa238, color_map[31] = 0xffac37);
	(color_map[32] = 0xffb535, color_map[33] = 0xffbe30);
	(color_map[34] = 0xffc724, color_map[35] = 0xffd000);
	(color_map[36] = 0xffda00, color_map[37] = 0xffe400);
	(color_map[38] = 0xffed00, color_map[39] = 0xfff700);
	(color_map[40] = 0x292f56, color_map[41] = 0x28345d, color_map[42] = 0x263963);
	(color_map[43] = 0x233e6a, color_map[44] = 0x1f4370, color_map[45] = 0x194876);
	(color_map[46] = 0x104e7c, color_map[47] = 0x005382, color_map[48] = 0x005987);
	(color_map[49] = 0x005e8d, color_map[50] = 0x006491, color_map[51] = 0x006994);
	(color_map[52] = 0x006f96, color_map[53] = 0x007498, color_map[54] = 0x00799a);
	(color_map[55] = 0x007f9c, color_map[56] = 0x00849e, color_map[57] = 0x00899f);
	(color_map[58] = 0x008fa1, color_map[59] = 0x0094a2, color_map[60] = 0x009aa3);
	(color_map[61] = 0x009fa4, color_map[62] = 0x00a5a4, color_map[63] = 0x00aba4);
	(color_map[64] = 0x00b0a4, color_map[65] = 0x00b6a3, color_map[66] = 0x00bca1);
	(color_map[67] = 0x00c39e, color_map[68] = 0x00c89b, color_map[69] = 0x00cd98);
	(color_map[70] = 0x00d295, color_map[71] = 0x1cd791, color_map[72] = 0x38dc8d);
	(color_map[73] = 0x4de189, color_map[74] = 0x5ee584, color_map[75] = 0x6fea80);
	(color_map[76] = 0x7eee7c, color_map[77] = 0x8ef278, color_map[78] = 0x9df674);
	(color_map[79] = 0xacfa70);
	return(select_color(color_map, i, max_i));
}

int	select_color(int *color_map, int i, int max_i)
{
	// double elements;
	double factor;

	factor = (39 / (double)max_i);
	i = factor * (double)i;
	if (i > 39)
		i = 39;
	else if (i < 0)
		i = 0;
	//aqui podria aplicar el ajuste de brillo de chat gpt (opcional)
	return (color_map[i]);
}
