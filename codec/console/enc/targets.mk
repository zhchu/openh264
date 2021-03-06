H264ENC_PREFIX=H264ENC
H264ENC_SRCDIR=codec/console/enc
H264ENC_CPP_SRCS=\
	$(H264ENC_SRCDIR)/./src/read_config.cpp\
	$(H264ENC_SRCDIR)/./src/welsenc.cpp\

H264ENC_OBJS += $(H264ENC_CPP_SRCS:.cpp=.o)
ifeq ($(USE_ASM), Yes)
H264ENC_ASM_SRCS=\

H264ENC_OBJS += $(H264ENC_ASM_SRCS:.asm=.o)
endif

OBJS += $(H264ENC_OBJS)
$(H264ENC_SRCDIR)/%.o: $(H264ENC_SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(INCLUDES) $(H264ENC_CFLAGS) $(H264ENC_INCLUDES) -c -o $@ $<

$(H264ENC_SRCDIR)/%.o: $(H264ENC_SRCDIR)/%.asm
	$(ASM) $(ASMFLAGS) $(ASM_INCLUDES) $(H264ENC_ASMFLAGS) $(H264ENC_ASM_INCLUDES) -o $@ $<

h264enc: $(H264ENC_OBJS) $(LIBS) $(H264ENC_LIBS) $(H264ENC_DEPS)
	$(CXX) -o $@  $(H264ENC_OBJS) $(H264ENC_LDFLAGS) $(H264ENC_LIBS) $(LDFLAGS) $(LIBS)

binaries: h264enc
BINARIES += h264enc
