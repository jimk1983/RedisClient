#Makefile的设置
include $(CURDIR)/setting.mk

##############通用部分#######################
#找到当前的Makefile下的目录文件夹，不包含子文件夹
dirs:=$(shell find . -maxdepth 1 -type d)

#在$(dirs)变量中，将所有的子目录，替换为./dir格式
dirs:=$(basename $(patsubst ./%,%,$(dirs)))

#过滤出vos下的所有子目录
dirs:=$(filter-out $(CURDIR),$(dirs))

#获取当前Makefile中的所有的子目录
SUBDIRS := $(dirs)

###################复制时候需要修改的地方##################
#libredisclient
LIBOBJSDIR=$(CURDIR)
LIBBINDIR=$(CURDIR)
LIBTARGET=$(TARGET)
################生成目标文件#####################
CUR_SOURCE=${wildcard *.c}
CUR_OBJS=${patsubst %.c, %.o, $(CUR_SOURCE)}
all:$(CUR_OBJS)
$(CUR_OBJS):%.o:%.c
	$(CC) $(CFLAGS) $^ -o $(LIBOBJSDIR)/$@ $(LDFLAGS) $(LSFLAGS)
ECHO:
	@echo $(SUBDIRS)

#执行libvos.a的打包命令, 注意本库所有的都要vos开头
LIBOBJS=$(LIBOBJSDIR)/*.o
libredisclient:
	$(AR) $(LIBBINDIR)/$(LIBTARGET) $(LIBOBJS)	
	
####################################

.PHONY:clean
clean:
	rm -rf $(LIBOBJSDIR)/*.o
	rm -rf $(LIBOBJSDIR)/*.a
