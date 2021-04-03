# �R���p�C��
COMPILER  = g++
# ���D���ȃt���O��
CXXFLAGS    = -g -Wall -Werror -std=c++11 -D_LINUX 
# ���C�u�����֌W�̎w��
ifeq "$(shell getconf LONG_BIT)" "64"
  LDFLAGS = -L/usr/local/lib -L/usr/lib
else
  LDFLAGS = -L/usr/local/lib -L/usr/lib
endif
# �C���N���[�h�p�X�̎w��B����������Ƃ��Ă����Ȃ���DEPENDS(�ˑ�)�t�@�C�������܂����Ȃ�
INCLUDE   = -I../include -I/usr/local/include -I./include -I./include/YanaPOnlineUtil 
# ���������ÓI���C�u����
TARGETS   = bin/libyanaponlineutil.a
# ���������o�C�i���t�@�C���̏o�̓f�B���N�g��
TARGETDIR = ./
# �\�[�X�R�[�h�̈ʒu
SRCROOT   = .
# ���ԃo�C�i���t�@�C���̏o�̓f�B���N�g��
OBJROOT   = ./obj
# �\�[�X�f�B���N�g���̒���(shell��)find�R�}���h�ő��j���ăT�u�f�B���N�g���܂Ń��X�g������
SRCDIRS  := $(shell find $(SRCROOT) -type d)
# �\�[�X�f�B���N�g��������foreach���߂őScpp�t�@�C�������X�g������
SOURCES   = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
# ��L��cpp�t�@�C���̃��X�g�����ɃI�u�W�F�N�g�t�@�C����������
OBJECTS   = $(addprefix $(OBJROOT)/, $(SOURCES:.cpp=.o))
# �\�[�X�f�B���N�g���Ɠ����\���Œ��ԃo�C�i���t�@�C���̏o�̓f�B���N�g�������X�g��
OBJDIRS   = $(addprefix $(OBJROOT)/, $(SRCDIRS))
# �ˑ��t�@�C��.d��.o�t�@�C��������
DEPENDS   = $(OBJECTS:.o=.d)

# �ˑ��t�@�C����ÓI���C�u���������
$(TARGETS): $(OBJECTS)
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	ar rv $(TARGETS) $(OBJECTS)
	@rm -f $(OBJECTS)

# ���ԃo�C�i���̃f�B���N�g�����@��Ȃ���.cpp�𒆊ԃt�@�C��.o��
$(OBJROOT)/%.o: $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(COMPILER) $(CXXFLAGS) -MD $(INCLUDE) -o $@ -c $<

# �ˑ��֌W�̍Đ���
depend:
$(OBJROOT)/%.d: $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(COMPILER) $(CXXFLAGS) -MM -MG $(INCLUDE) -o $@ -c $<

# �N���[��
clean:
	@rm -rf obj

# ���r���h
rebuild:
	@make clean
	@make

# �ˑ��֌W�t�@�C��
-include $(DEPENDS)
