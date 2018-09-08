#执行方法：
#1、首先需要有sudo执行权限，最好能设置成免输入密码，简化操作
#2、根据需求修改起始日期、月份，结束日期月份等参数
#3、远程登录，执行该脚本，断开连接。每执行一次造一次记录，并提示所造数据的日期。
#4、循环执行第三步操作，直到出现done代表结束，注：可以使用crt脚本写个按钮来简化操作，如：
#														./setdate_1.sh\r\n
#														exit\r\n
#5、可以通过last命令查看造记录结果
#!/bin/bash

#造记录的临时数据目录
BASE="/home/lby/data"

#标记是否初始化
FIRST=$BASE/first

#需要造数据的日期
DAY="1 3 5 8 10 12 15 17 19 22 24 26 27"
MONTH="3 4 5"

#用于判断结束日期
END_M=5
END_D=13

BEGIN_D="2016-3-1 09:13:22"

if [ ! -f $FIRST ];then
	mkdir $BASE -p
	echo "first set time"
	sudo date --set "$BEGIN_D" 
	sudo hwclock -w 
	sudo touch $FIRST
	date >> $FIRST			
	echo "Init ok!!!"
else
	for month in $MONTH;do

		echo "check for month $month"
		if [ ! -d $month ];then
			sudo mkdir -p $BASE/$month
		fi
		
		for day in $DAY;do
			if [ $month -ge $END_M ];then
				if [ $day -ge $END_D ];then
					echo "done!!!!"
					exit
				fi
			fi

			if [ ! -f $BASE/$month/$day ];then
				echo "make data for $BASE/$month/$day"
				sudo date --set "2016-$month-$day 18:$day:$month"
				sudo touch $BASE/$month/$day
				sudo hwclock -w 
				exit
			fi
		done		
	done
fi
