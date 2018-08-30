异常解决，初始化数据库，然后重新克隆
打开git-bash.exe
1. cd ~/.ssh/
2. git config --global user.name "名称"
3. git config --global user.email "邮箱地址"
4. ssh-keygen -t rsa -C "邮箱地址"

> 按三次回车，最后在.ssh文件夹下得到id_rsa和id_rsa.pub两个文件。


5. eval "$(ssh-agent -s)"  
6. ssh-add ~/.ssh/id_rsa  
7. 第七步不同系统键入不同的命令  
   clip < ~/.ssh/id_rsa.pub   (windows)  
   pbcopy < ~/.ssh/id_rsa.pub (macOS)  
   sudo apt-get install xclip  (linux 1)  
   xclip -sel clip < ~/.ssh/id_rsa.pub (linux 2)  


接下来 id_rsa中的内容便是私钥，id_rsa.pub中的内容便是公钥。  
将公钥粘贴至github上，即可完工  


接下来是测试连接  
ssh -T git@github.com  
ssh克隆方式 打开VS code 执行git克隆   git@github.com:xyz1178700373/xiaohao.git  
在git中直接输入任意消息提交  