�쳣�������ʼ�����ݿ⣬Ȼ�����¿�¡
��git-bash.exe
��   cd ~/.ssh/    �����û�ж�Ӧ���ļ��У���ִ��  mkdir  ./.ssh��

��  git config --global user.name "bobodesu"

��  git config --global user.email "1808297916@qq.com"

��  ssh-keygen -t rsa -C "1808297916@qq.com"
�����λس��������.ssh�ļ����µõ�id_rsa��id_rsa.pub�����ļ���

��˽Կ��ӵ� ssh-agent
������������� ssh-agent ��
eval "$(ssh-agent -s)"

�����������˽Կ��ӵ� ssh-agent��
ssh-add ~/.ssh/id_rsa

��� SSH Key
/* windows ϵͳ */
clip < ~/.ssh/id_rsa.pub

/* macOS ϵͳ */
pbcopy < ~/.ssh/id_rsa.pub

/* Linux ϵͳ */
sudo apt-get install xclip
xclip -sel clip < ~/.ssh/id_rsa.pub

C:\Users\11787\.ssh  ʹ�ù�Կ  gitub��setting��ssh��
id_rsa�е����ݱ���˽Կ��id_rsa.pub�е����ݱ��ǹ�Կ��
��������
ssh -T git@github.com
ssh��¡��ʽ ��VS code ִ��git��¡   git@github.com:xyz1178700373/xiaohao.git

��git��ֱ������������Ϣ�ύ��     ****Ȼ��������****