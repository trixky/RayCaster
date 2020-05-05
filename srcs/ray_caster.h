#ifndef RAY_CASTER_H
# define RAY_CASTER_H
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include "mlx.h"

/*
** ==========================================
** ................................................... DEFINE
** ==========================================
*/

# define B_M_O_1_PATH			"./textures/alien_1.xpm"
# define B_M_O_2_PATH			"./textures/alien_2.xpm"
# define B_M_O_3_PATH			"./textures/barrel.xpm"
# define B_M_O_4_PATH			"./textures/poing.xpm"

# define LIFE_COLOR			50000
# define SCREENSHOT_PATH	"screen.bmp"
# define BYTES_PER_PIXEL 	3
# define FILE_HEADER_SIZE	14
# define INFO_HEADER_SIZE	40

# define BUFFER_SIZE		128

# define NO					1
# define SO					2
# define WE					3
# define EA					4
# define GUN_PATH			"./textures/pomp.xpm"

# define FALSE				0
# define TRUE				1

# define MAX_WIDTH			2560
# define MAX_HEIGHT			1400
# define WINDOW_WIDTH		300
# define WINDOW_HEIGHT		1300

# define WINDOW_TITLE		"title of window"

# define MAX_LENGTH_FSC 	150
# define ROOF_COLOR			6777777777
# define FLOOR_COLOR		1111111111
# define OBJECT_WIDTH		0.550000
# define OBJECT_HEIGHT		0.700000

# define LIMIT_PRECISION	1.100000

# define R_SPEED			2
# define W_SPEED			0.1
# define FRONT				13
# define RIGHT				2
# define BACK				1
# define LEFT				0

# define RAD_0				0.000000
# define RAD_30				0.523599
# define RAD_60				1.047198
# define RAD_90				1.570796
# define RAD_120			2.094395
# define RAD_150			2.617994
# define RAD_180			3.141593
# define RAD_210			3.665191
# define RAD_240			4.188790
# define RAD_270			4.712389
# define RAD_300			5.235988
# define RAD_330			5.759586
# define RAD_360			6.283185

# define INF				1
# define SUP				2

# define IR_R				0
# define IR_NO				1
# define IR_SO				2
# define IR_WE				3
# define IR_EA				4
# define IR_S				5
# define IR_F				6
# define IR_C				7

/*
** ==========================================
** ................................................... STRUCTURES
** ==========================================
*/

typedef	struct s_obj	t_obj;

typedef struct	s_sprite
{
	void	*sprite;
	int		*sprite_data;
	int		sprite_bpp;
	int		sprite_size_line;
	int		sprite_endian;
	int		width;
	int		height;
	int		size;
}				t_sprite;

struct			s_obj
{
	float		pos_x;
	float		pos_y;
	int			start;
	int			index;
	int			end;
	float		direction;
	float		length;
	float		width;
	float		height;
	float		o_ray;
	t_obj		*next;
	t_sprite	*w_ob;
};

typedef struct	s_st
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	int		ret;
	int		last_fd;
	int		lu;
}				t_st;

typedef struct	s_map
{
	int		fd;
	int		width;
	int		height;
	char	*line;
	int		**array;
}				t_map;

typedef struct	s_gun
{
	int color;
	int x_start;
	int x_index;
	int x_end;
	int y_start;
	int y_index;
	int y_end;
}				t_gun;

typedef struct	s_vie
{
	int color;
	int x_start;
	int x_index;
	int x_end;
	int y_start;
	int y_index;
	int y_end;
}				t_vie;

typedef struct	s_data
{
	float	incrementation;
	int		window_width;
	int		window_height;
	void	*mlx;
	void	*window;
	int		x_ray;
	void	*screen;
	int		*screen_data;
	int		screen_bpp;
	int		screen_size_line;
	int		screen_endian;
	int		max_screen_pix;
	char	*path_texture_no;
	char	*path_texture_so;
	char	*path_texture_we;
	char	*path_texture_ea;
	char	*path_texture_s;
	int		c_color;
	int		f_color;
}				t_data;

typedef struct	s_fsc
{
	float	direction;
	float	cp_direction;
	float	x_pos_x;
	float	x_pos_y;
	float	x_lenght;
	int		x_wall_touched;
	float	x_ray_of_wall;
	float	x_angle;
	t_obj	*x_obj;
	float	y_pos_x;
	float	y_pos_y;
	float	y_lenght;
	float	y_ray_of_wall;
	int		y_wall_touched;
	float	y_angle;
	t_obj	*y_obj;
	float	closest_lenght_obj;
}				t_fsc;

typedef struct	s_player
{
	float	pos_x;
	float	pos_y;
	int		direction;
}				t_player;

typedef struct	s_all
{
	t_data		data;
	t_sprite	*ptr_wall_x;
	t_sprite	*ptr_wall_y;
	t_sprite	n_wall;
	t_sprite	e_wall;
	t_sprite	s_wall;
	t_sprite	o_wall;
	t_sprite	object;
	t_sprite	object_2;
	t_sprite	object_b;
	t_sprite	object_bb;
	t_sprite	poing;
	t_sprite	*object_b_ptr;
	t_sprite	gun;
	t_player	player;
	t_fsc		fsc;
	t_map		map;
	int			nothing;
	clock_t		start_clock;
}				t_all;

/*
** ==========================================
** ................................................... PROTOTYPES
** ==========================================
*/

/*
** ========================================== G N L
*/

int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
void			ft_init_line_buffer_lu(char ***line, char *buffer, int *lu);
int				ft_fd_manager(int fd, int *i, int *ret, int *last_fd);
void			ft_add_char(char **line, char c);

/*
** ========================================== L S T
*/

void			ft_lstadd_front(t_obj **alst, t_obj *new);
void			ft_lstclear(t_obj **lst);
t_obj			*ft_lstnew(t_all *all, float x, float y, char c);

/*
** ============================================= C U B   3 D
** ====================== tools_1.c
*/

int				ft_strlen(char *str);
float			ft_degree_to_rad(float degree);
float			ft_rad_to_degree(float rad);
float			ft_next_block_distance(float position, int mod);
float			ft_cut_float(float nbr);

/*
** ====================== tools_2.c
*/

int				ft_infinite_rotation_player(t_all *all);
float			ft_fsc_inifinit_rotation(float rad);
int				ft_check_case_exist(float y, float x, t_all *all);
int				ft_key_isfordeplacement(int keycode);
void			ft_deplacement_limitation(t_all *all);

/*
** ====================== tools_3.c
*/

void			ft_deplacement(t_all *all, int mod);
float			ft_absolute_float(float nbr);
int				ft_limit(int nbr, int limit);
void			*ft_free(void *ptr);
char			*ft_generate_empty_str(void);

/*
** ====================== tools_4.c
*/

int				ft_atoi(char *str);
int				ft_free_and_return(void **ptr_1, void **ptr_2,
				void **ptr_3, void **ptr_4);
int				ft_antiseg_leave_window(int nbr, int limit);
void			ft_clean_screen(t_all *all);
void			infinit_rot_player(t_all *all, int dir_dep);

/*
** ====================== ft_set_line_map.c
*/

int				ft_is_map_char(char c);
int				ft_is_pole(t_all *all, char c, int x, int y);
int				ft_set_line_map(t_all *all, char *str, int *line);

/*
** ====================== build_frame_if.c
*/

void			ft_shot_faisceau_90(t_all *all);
void			ft_shot_faisceau_180(t_all *all);
void			ft_shot_faisceau_270(t_all *all);
void			ft_shot_faisceau_360(t_all *all);

/*
** ====================== build_frame_x.c
*/

int				ft_rad_90_x(t_all *all);
int				ft_rad_180_x(t_all *all);
int				ft_rad_270_x(t_all *all);
int				ft_rad_360_x(t_all *all);

/*
** ====================== build_frame_y.c
*/

int				ft_rad_90_y(t_all *all);
int				ft_rad_180_y(t_all *all);
int				ft_rad_270_y(t_all *all);
int				ft_rad_360_y(t_all *all);

/*
** ====================== build_frame.c
*/

void			ft_frame(t_all *all);
int				ft_shot_faisceau(t_all *all);

/*
** ====================== generate_ray_wall.c
*/

void			ft_generate_ray_wall_x_cut(t_all *all, int y_start,
				int y_index, int y_end);
void			ft_generate_ray_wall_y_cut(t_all *all, int y_start,
				int y_index, int y_end);
void			ft_generate_ray_wall(t_all *all);

/*
** ====================== generate_ray_obj_x_object_dir.c
*/

void			ft_x_object_1_dir(t_all *all, t_obj *x_temp);
void			ft_x_object_2_dir(t_all *all, t_obj *x_temp);
void			ft_x_object_3_dir(t_all *all, t_obj *x_temp);
void			ft_x_object_4_dir(t_all *all, t_obj *x_temp);

/*
** ====================== generate_ray_obj_x_object.c
*/

void			ft_x_object(t_all *all, t_obj *x_temp);
void			ft_x_object_1(t_all *all, t_obj *x_temp);
void			ft_x_object_2(t_all *all, t_obj *x_temp);
void			ft_x_object_3(t_all *all, t_obj *x_temp);
void			ft_x_object_4(t_all *all, t_obj *x_temp);

/*
** ====================== generate_ray_obj_y_object_dir.c
*/

void			ft_y_object_5_dir(t_all *all, t_obj *x_temp);
void			ft_y_object_6_dir(t_all *all, t_obj *x_temp);
void			ft_y_object_7_dir(t_all *all, t_obj *x_temp);
void			ft_y_object_8_dir(t_all *all, t_obj *x_temp);

/*
** ====================== generate_ray_obj_y_object.c
*/

void			ft_y_object(t_all *all, t_obj *y_temp);
void			ft_y_object_5(t_all *all, t_obj *y_temp);
void			ft_y_object_6(t_all *all, t_obj *y_temp);
void			ft_y_object_7(t_all *all, t_obj *y_temp);
void			ft_y_object_8(t_all *all, t_obj *y_temp);

/*
** ====================== generate_ray_obj.c
*/

void			ft_init_length_object(t_all *all, t_obj *x_temp, t_obj *y_temp);
void			ft_generate_ray_obj(t_all *all);

/*
** ====================== close_tools.c
*/

void			ft_free_map_array(t_all *all);
void			ft_print_error(int error_id);
int				ft_close_by_red_cross(t_all *all);
void			ft_close_free_1(t_all *all);
void			ft_close_free_2(t_all *all);

/*
** ====================== close.c
*/

int				ft_close(t_all *all, int error_id);

/*
** ====================== start_init.c
*/

void			ft_start_init(t_all *all);
void			ft_init_mlx_cut_1(t_all *all);
void			ft_init_mlx_cut_2(t_all *all);
void			ft_init_mlx(t_all *all);

/*
** ====================== start_check.c
*/

void			ft_check_parsing(t_all *all);
void			ft_recize_window(t_all *all);
void			ft_check_all_path(t_all *all);

/*
** ====================== key_hook.c
*/

void			ft_kill_secret_door(t_all *all);
void			ft_kill_alien(t_all *all);
int				key_hook(int keycode, t_all *all);

/*
** ====================== parser_tools_1.c
*/

void			ft_init_is_readed(int is_readed[8]);
int				ft_exit_parser(int fd, char ***line);
int				ft_is_number(char c);
int				ft_is_whitespace(char c);

/*
** ====================== parser_tools_2.c
*/

int				ft_parse_no(char *line, t_all *all);
int				ft_parse_so(char *line, t_all *all);
int				ft_parse_we(char *line, t_all *all);
int				ft_parse_ea(char *line, t_all *all);
int				ft_parse_s(char *line, t_all *all);

/*
** ====================== parser_tools_3.c
*/

int				ft_parse_color(char *str, int *index, int j);
int				ft_parse_f(char *line, t_all *all);
int				ft_parse_c(char *line, t_all *all);

/*
** ====================== parser_tools_4.c
*/

int				ft_parse_r_init(t_all *all, int *i, char **width_str,
				char **height_str);
void			ft_parse_r_finish(t_all *all, char **width_str,
				char **height_str);
int				ft_parse_r(char *line, t_all *all, char	*width_str,
				char *height_str);
int				ft_im_last_readed(t_all *all);
void			ft_init_array(t_all *all);

/*
** ====================== parser_tools_5.c
*/

int				ft_check_border(t_all *all);
int				ft_parse_1_1_1_1(char **line, t_all *all, int fd, int first);
int				ft_parse_1_1_1(char **line, t_all *all, int fd);
int				ft_parse_1_1(char **line, char *path_map, t_all *all);
int				ft_parse_1(int fd, char *path_map, char **line, t_all *all);

/*
** ====================== parser.c
*/

int				ft_is_first_letter(char **line);
int				ft_parser_first_line(t_all *all, char **line,
				int fd, char *path_map);
int				ft_parser(t_all *all, char *path_map);

/*
** ====================== gun.c
*/

void			ft_init_gun(t_all *all, t_gun *gun);
void			ft_put_gun(t_all *all);

/*
** ====================== vie.c
*/

void			ft_init_vie(t_all *all, t_vie *vie);
void			ft_put_vie(t_all *all);

/*
** ====================== bmp.c
*/

int				create_bmp(t_all *all);
void			write_rgb(t_all *all, int height, int width, int fd);
void			generate_bitmap_image(t_all *all, int height, int width);
unsigned char	*create_bitmap_file_header(int height,
				int width, int padding_size);
unsigned char	*create_bitmap_info_header(int height, int width);

/*
** ====================== main.c
*/

int				ft_inifinit_hook(t_all *all);

/*
** ====================== main.c
*/

int				ft_str_is_save(char *str);
int				ft_cub_ext(char *str);
int				ft_check_null(t_all *all);
void			ft_first_screen(t_all *all);
int				ft_check_null(t_all *all);

#endif
