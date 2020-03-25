FROM fedora:32

RUN yum info glibc
RUN uname -a

RUN yum install -y glibc-devel.i686 gcc strace
ADD test-time64.c /tmp
RUN cd /tmp && gcc -m32 test-time64.c && strace ./a.out && stat foo
