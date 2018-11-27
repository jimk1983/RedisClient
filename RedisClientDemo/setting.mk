#公共部分
CC=gcc
CFLAGS=-c 
MAKE=make
AR=ar cr
RM=-rm -rf
CFLAGS +=-Wall -g #-Werror -O3  	#将-Werror将告警当作错误处理


###########################
#公共属性定义
TARGET=RedisClientDemo
OUTPUTBINSDIR=$(CURDIR)
OUTPUTOBJSDIR=$(CURDIR)

##################################
#添加系统配置的头文件目录
CFLAGS+=-I$(CURDIR)
##################################
#添加内部库的头文件目录
#lib头文件包含目录
CFLAGS += -I$(ROOTDIR)/Libs/include
#依赖的库放置有顺序的，需要按依赖前后来放置,对后面有依赖的放前面
LSFLAGS +=-L$(ROOTDIR)/Libs/Bin -lredisclient -lhiredis

##################################
LDFLAGS = -ldl -lpthread -lrt -lm #-ldb


















