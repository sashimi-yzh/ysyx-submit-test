#!/bin/bash  

  
# 输入和输出文件的路径  

VERSION=V5
ROOT="NPC_HOME"

eval CONFIG_FILE="\$$ROOT/config/.config"  

eval AUTO_H="\$$ROOT/wavesim_file/include/auto.h"
eval AUTO_V="\$$ROOT/vfile/ysyx_23060229_auto"


# 检查.config文件是否存在  
if [ ! -f "$CONFIG_FILE" ]; then  
    echo "Error: $CONFIG_FILE does not exist."  
    exit 1  
fi  


# 创建一个新的auto.h文件，或者覆盖现有的文件  
> "$AUTO_H"  

# 遍历.config文件中的每一行  
while IFS= read -r line; do  
    # 检查该行是否是一个配置选项（即，它是否以CONFIG_开头
    if [[ $line =~ ^CONFIG_ ]]; then  

        # 提取配置选项的名字和值  

        name=${line%=*}  
        value=${line#*=}  


        # 将配置选项转换为宏定义，并写入auto.h文件  
        # 注意：这里假设值为"y"表示启用，其他值（如"n"或"m"）表示禁用  

        if [ "$value" = "y" ]; then  
            echo "#define $name 1" >> "$AUTO_H"  
		elif [ "$value" = "n" ]; then
            echo "/* #undef $name */" >> "$AUTO_H"  
		else
			echo "#define $name $value" >> "$AUTO_H"
		fi
	    #echo "#define $name $value" >> "$AUTO_H"
    fi  

done < "$CONFIG_FILE" 


echo "$AUTO_H has been generated successfully."





> "$AUTO_V" #创建ysyx_23060229_auto.v文件

# 遍历.config文件中的每一行  
while IFS= read -r line; do
    # 检查该行是否是一个配置选项（即，它是否以CONFIG_开头
    if [[ $line =~ ^CONFIG_ ]]; then

        # 提取配置选项的名字和值  
        name=${line%=*}
        value=${line#*=}

        # 将配置选项转换为宏定义，并写入ysyx_23060229_auto.v文件  
        # 注意：这里假设值为"y"表示启用，其他值（如"n"或"m"）表示禁用  

        if [ "$name" = "CONFIG_FLASH" ] && [ "$value" = "y" ]; then
            echo "\`define ysyx_23060229_$name 1" >> "$AUTO_V"
		fi
		
		if [ "$name" = "CONFIG_FAST_FLASH" ] && [ "$value" = "y" ]; then
			echo "\`define ysyx_23060229_$name 1" >> "$AUTO_V"
		fi
        
		if [ "$name" = "CONFIG_MROM" ] && [ "$value" = "y" ]; then
            echo "\`define ysyx_23060229_$name 1" >> "$AUTO_V"
		fi

		if [ "$name" = "CONFIG_CALIB_AXI4" ] && [ "$value" = "y" ]; then
            echo "\`define ysyx_23060229_$name 1" >> "$AUTO_V"
        fi

		if [ "$name" = "CONFIG_CALIB_APB" ] && [ "$value" = "y" ]; then
            echo "\`define ysyx_23060229_$name 1" >> "$AUTO_V"
        fi

		if [ "$name" = "CONFIG_N" ]; then
            echo "\`define ysyx_23060229_$name $value" >> "$AUTO_V"
        fi
		
		if [ "$name" = "CONFIG_M" ]; then
            echo "\`define ysyx_23060229_$name $value" >> "$AUTO_V"
        fi

		if [ "$name" = "CONFIG_ITRACE" ]; then
			echo "\`define ysyx_23060229_$name 1" >> "$AUTO_V"
		fi
		
	fi

done < "$CONFIG_FILE"

echo "$AUTO_V has been generated successfully."


