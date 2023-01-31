 #!/bin/bash
blue=$(tput setaf 4)
normal=$(tput sgr0)

printf "${blue}\n\ncolor_defined_twice.cub :\n${normal}$"
./cub3D maps/invalid_maps/color_defined_twice.cub

printf "${blue}\n\nempty_line_in_map.cub :\n${normal}$"
./cub3D maps/invalid_maps/empty_line_in_map.cub

printf "${blue}\n\nempty.cub :\n${normal}$"
./cub3D maps/invalid_maps/empty.cub

printf "${blue}\n\nextra_color.cub :\n${normal}$"
./cub3D maps/invalid_maps/extra_color.cub

printf "${blue}\n\nextra_texture.cub :\n${normal}$"
./cub3D maps/invalid_maps/extra_texture.cub

printf "${blue}\n\nmap_not_closed_bottom.cub :\n${normal}$"
./cub3D maps/invalid_maps/map_not_closed_bottom.cub

printf "${blue}\n\nmap_not_closed_left.cub :\n${normal}$"
./cub3D maps/invalid_maps/map_not_closed_left.cub

printf "${blue}\n\nmap_not_closed_right.cub :\n${normal}$"
./cub3D maps/invalid_maps/map_not_closed_right.cub

printf "${blue}\n\nmap_not_closed_top.cub :\n${normal}$"
./cub3D maps/invalid_maps/map_not_closed_top.cub

printf "${blue}\n\nmap_only_wall.cub :\n${normal}$"
./cub3D maps/invalid_maps/map_only_wall.cub

printf "${blue}\n\nmap_tex_jpg.cub :\n${normal}$"
./cub3D maps/invalid_maps/map_tex_jpg.cub


printf "${blue}\n\nmap_too_small.cub :\n${normal}$"
./cub3D maps/invalid_maps/map_too_small.cub

printf "${blue}\n\nmissing_color.cub :\n${normal}$"
./cub3D maps/invalid_maps/missing_color.cub

printf "${blue}\n\nmultiple_start_positions.cub :\n${normal}$"
./cub3D maps/invalid_maps/multiple_start_positions.cub

printf "${blue}\n\nno_ceiling.cub :\n${normal}$"
./cub3D maps/invalid_maps/no_ceiling.cub

printf "${blue}\n\nno_color.cub :\n${normal}$"
./cub3D maps/invalid_maps/no_color.cub

printf "${blue}\n\nno_floor.cub :\n${normal}$"
./cub3D maps/invalid_maps/no_floor.cub

printf "${blue}\n\nno_player.cub :\n${normal}$"
./cub3D maps/invalid_maps/no_player.cub

printf "${blue}\n\nno_start_position.cub :\n${normal}$"
./cub3D maps/invalid_maps/no_start_position.cub

printf "${blue}\n\nno_texture_NO.cub :\n${normal}$"
./cub3D maps/invalid_maps/no_texture_NO.cub

printf "${blue}\n\nnot_right_char_in_map.cub :\n${normal}$"
./cub3D maps/invalid_maps/not_right_char_in_map.cub

printf "${blue}\n\nplayer_outof_wall.cub :\n${normal}$"
./cub3D maps/invalid_maps/player_outof_wall.cub

printf "${blue}\n\nrandom_text_in_map.cub :\n${normal}$"
./cub3D maps/invalid_maps/random_text_in_map.cub

printf "${blue}\n\nspaces_after_zero.cub :\n${normal}$"
./cub3D maps/invalid_maps/spaces_after_zero.cub

printf "${blue}\n\nto_small.cub :\n${normal}$"
./cub3D maps/invalid_maps/to_small.cub

printf "${blue}\n\nwrong_color_code_high.cub :\n${normal}$"
./cub3D maps/invalid_maps/wrong_color_code_high.cub

printf "${blue}\n\nwrong_color_code_low.cub :\n${normal}$"
./cub3D maps/invalid_maps/wrong_color_code_low.cub

printf "${blue}\n\nwrong_name.cob :\n${normal}$"
./cub3D maps/invalid_maps/wrong_name.cob

printf "${blue}\n\nwrong_texture.cub :\n${normal}$"
./cub3D maps/invalid_maps/wrong_texture.cub
