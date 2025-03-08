/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:21:21 by alex              #+#    #+#             */
/*   Updated: 2025/03/08 12:57:32 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

set_pixel *set_pixel_functions(set_pixel *array_func)
{
	array_func[0] = fmandelbroot_set;
	array_func[1] = fmandelbroot_set;
	array_func[2] = fmandelbroot_set;
	array_func[3] = fmandelbroot_set;
	array_func[4] = fmandelbroot_set;
	array_func[5] = fmandelbroot_set;
	array_func[6] = fmandelbroot_set;
	array_func[7] = fmandelbroot_set;
	array_func[8] = fmandelbroot_set;
	array_func[9] = fmandelbroot_set;
	array_func[10] = fmandelbroot_set;
	array_func[11] = fmandelbroot_set;
	array_func[12] = fmandelbroot_set;
	array_func[13] = fmandelbroot_set;
	array_func[14] = fmandelbroot_set;
	array_func[15] = fmandelbroot_set;
	array_func[16] = fmandelbroot_set;
	array_func[17] = fmandelbroot_set;
	array_func[18] = fmandelbroot_set;
	array_func[19] = fmandelbroot_set;
	array_func[20] = fmandelbroot_set;
	array_func[21] = fmandelbroot_set;
	array_func[22] = fmandelbroot_set;
	array_func[23] = fmandelbroot_set;
	array_func[24] = fmandelbroot_set;
	array_func[25] = fmandelbroot_set;
	array_func[26] = fmandelbroot_set;
	array_func[27] = fmandelbroot_set;
	array_func[28] = fmandelbroot_set;
	array_func[29] = fmandelbroot_set;
	array_func[30] = fmandelbroot_set;
	array_func[31] = fmandelbroot_set;
	array_func[32] = fmandelbroot_set;
	array_func[33] = fmandelbroot_set;
	array_func[34] = fmandelbroot_set;
	array_func[35] = fmandelbroot_set;
	array_func[36] = fmandelbroot_set;
	array_func[37] = fmandelbroot_set;
	array_func[38]
}

llamar a funcion que llene un array de structs para iterar sobre el lo optimo seria  hacerlo con lgobal pero en este proyecyo no se puede 
habria que reservar memeria para cada strect y sun contenid 

Lo que si que se uede hacer es con el array de funiones queqye tambieneseai optimo declararlo en una global

preguntar