#公共部分
CC=gcc
CFLAGS=-c 
MAKE=make
AR=ar cr
RM=-rm -rf
CFLAGS +=-Wall -g #-Werror -O3  	#将-Werror将告警当作错误处理


###########################
#公共属性定义
TARGET=libredisclient.a
OUTPUTBINSDIR=$(CURDIR)/Bin

##################################
#添加系统配置的头文件目录
CFLAGS+=-I$(CURDIR)
##################################
#添加内部库的头文件目录
#lib头文件包含目录
CFLAGS += -I$(ROOTDIR)/Libs/include
LSFLAGS +=-L$(ROOTDIR)/Libs/Bin -lhiredis

##################################
LDFLAGS = -ldl -lpthread -lrt -lm #-ldb


















