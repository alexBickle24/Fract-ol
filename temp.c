void	manage_keys2(int keysym, t_mlx_enviroment *mlx)
{
	if (keysym == XK_Right)
	{
		mlx->img_data->with[0] -= (0.5 * mlx->img_data->zoom);
		render_set(mlx, mlx->img_data);
	}
	else if (keysym == XK_Up)
	{
		mlx->img_data->with[1] -= (0.5 * mlx->img_data->zoom);
		render_set(mlx, mlx->img_data);
	}
	else if (keysym == XK_Down)
	{
		mlx->img_data->with[1] += (0.5 * mlx->img_data->zoom);;
		render_set(mlx, mlx->img_data);
	}
	return (0);
}


int		manage_key(int keysym, t_mlx_enviroment *mlx)
{
	char	happend;
	
	happend = 0;
	if (keysym == XK_Escape)
		close_handler(mlx);
	if (keysym == XK_plus)
		(mlx->img_data->max_iter += 10, happend = 1);
	else if (keysym == XK_minus)
		(mlx->img_data->max_iter -= 10, happend = 1);
	else if (keysym == XK_Left)
		(mlx->img_data->with[0] += (0.5 * mlx->img_data->zoom), happend = 1);
	else if (keysym == XK_Right)
		(mlx->img_data->with[0] -= (0.5 * mlx->img_data->zoom), happend = 1);
	else if (keysym == XK_Up)
		(mlx->img_data->with[1] -= (0.5 * mlx->img_data->zoom), happend = 1);
	else if (keysym == XK_Down)
		(mlx->img_data->with[1] += (0.5 * mlx->img_data->zoom), happend = 1);
	if (happend)
		render_set(mlx, mlx->img_data);
	return (-1);
}

//LA PRIMERA PALETA
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

//PATELA ! EXTENDIDA
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
//NUEVA PALETA AZUL_AMRILLO
(color_map[0] = 0x292f56, color_map[1] = 0x28345d, color_map[2] = 0x263963);
(color_map[3] = 0x233e6a, color_map[4] = 0x1f4370, color_map[5] = 0x194876);
(color_map[6] = 0x104e7c, color_map[7] = 0x005382, color_map[8] = 0x005987);
(color_map[9] = 0x005e8d, color_map[10] = 0x006491, color_map[11] = 0x006994);
(color_map[12] = 0x006f96, color_map[13] = 0x007498, color_map[14] = 0x00799a);
(color_map[15] = 0x007f9c, color_map[16] = 0x00849e, color_map[17] = 0x00899f);
(color_map[18] = 0x008fa1, color_map[19] = 0x0094a2, color_map[20] = 0x009aa3);
(color_map[21] = 0x009fa4, color_map[22] = 0x00a5a4, color_map[23] = 0x00aba4);
(color_map[24] = 0x00b0a4, color_map[25] = 0x00b6a3, color_map[26] = 0x00bca1);
(color_map[27] = 0x00c39e, color_map[28] = 0x00c89b, color_map[29] = 0x00cd98);
(color_map[30] = 0x00d295, color_map[31] = 0x1cd791, color_map[32] = 0x38dc8d);
(color_map[33] = 0x4de189, color_map[34] = 0x5ee584, color_map[35] = 0x6fea80);
(color_map[36] = 0x7eee7c, color_map[37] = 0x8ef278, color_map[38] = 0x9df674);
(color_map[39] = 0xacfa70);

//OTOÑO
(color_map[0] = 0xD46E29, color_map[1] = 0xE17633, color_map[2] = 0xF07A3C);
(color_map[3] = 0xF78447, color_map[4] = 0xF88F51, color_map[5] = 0xF99A5A);
(color_map[6] = 0xFFA564, color_map[7] = 0xFFB06F, color_map[8] = 0xFFBB7A);
(color_map[9] = 0xFFCA85, color_map[10] = 0xFFD18F, color_map[11] = 0xFFDC9A);
(color_map[12] = 0xFFDF9D, color_map[13] = 0xFFE29F, color_map[14] = 0xFFD78A);
(color_map[15] = 0xFFD280, color_map[16] = 0xFFD070, color_map[17] = 0xFFCC00);
(color_map[18] = 0xFFD700, color_map[19] = 0xF4B800, color_map[20] = 0xF1A300);
(color_map[21] = 0xE59400, color_map[22] = 0xD57E00, color_map[23] = 0xD2691E);
(color_map[24] = 0x8B4513, color_map[25] = 0xA52A2A, color_map[26] = 0x6B4226);
(color_map[27] = 0x5B3A29, color_map[28] = 0x4E3629, color_map[29] = 0x3E2A1F);
(color_map[30] = 0x2F2219, color_map[31] = 0x1F1F1F, color_map[32] = 0xBEBEBE);
(color_map[33] = 0xA9A9A9, color_map[34] = 0x808080, color_map[35] = 0x696969);
(color_map[36] = 0x505050, color_map[37] = 0x383838, color_map[38] = 0x2F2F2F);
(color_map[39] = 0x1F1F1F);