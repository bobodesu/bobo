git init        #创建版本库 repository  
git add         #文件添加到暂存区  
> 示例：  
> git add readme.txt   
> git add 1.cpp 2.cpp   
git commit     #将暂存区提交到仓库  
> 示例：  
> git commit -m "提交了readme文件"  
git status      #获取工作区的状态  
git diff        #对比修改的内容  
> 示例：
> git diff readme.txt  
git reset       #版本库穿梭  
> 示例：  
> git reset --hard "HEAD^"      //回到上一个提交版本  
> git reset --hard "HEAD^^"     //回到上上次提交版本  
> git reset --hard e475afc      //回到e475afc提交版本  
git log         #查看此提交版本的历史（查看此前驱节点）  
git relog       #查看提交版本命令日志（查看所有版本变更历史，能够回到未来）  
git checkout -- "filename"    #将工作区的文件撤销  
> 示例：  
> git checkout -- readme.txt    //还原该文件到暂存区或者当前版本库的状态  
git remote add origin     #关联一个远程库
> 示例：
> git remote add oriigin git@server-name:path/repo-name.git
git push        #推送本地版本
> 示例：  
> git push -u origin master     //第一次推送  
> git push                      //之后的master分支可以省略  
git clone       #从远程库克隆  
git branch      #查看当前分支，当前分支为*号
git branch "branchname"     #创建分支
git branch -d "branchname"  #删除分支(未合并的分支不允许删除)
git branch -D "branchname"  #强行删除分支
git checkout "branchname"   #切换分支
git checkout -b "name"      #创建分支并切换
> git checkout -b dev => git branch dev & git chceckout dev
git merge "branchname"      #将分支合并到当前分支
git log --graph             #查看分支合并图
git stash                   #将当前工作现场储藏起来
git stash list              #查看工作现场
git stash pop               #恢复工作现场
