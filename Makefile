EXECS= init-IMT2019079 doc-IMT2019079 visitor-IMT2019079

all: $(EXECS)

init-IMT2019079: init-IMT2019079.c mysemops-IMT2019079.c mysemops-IMT2019079.h configs-IMT2019079.h
	gcc -o init-IMT2019079 init-IMT2019079.c mysemops-IMT2019079.c


doc-IMT2019079: doc-IMT2019079.c mysemops-IMT2019079.c mysemops-IMT2019079.h configs-IMT2019079.h
	gcc -o doc-IMT2019079 doc-IMT2019079.c mysemops-IMT2019079.c

visitor-IMT2019079: visitor-IMT2019079.c mysemops-IMT2019079.c mysemops-IMT2019079.h configs-IMT2019079.h
	gcc -o visitor-IMT2019079 visitor-IMT2019079.c mysemops-IMT2019079.c

clean:
	rm -f $(EXECS)