->GitHub:
https://guides.github.com/activities/hello-world/
->Git:
https://git-scm.com/download/win


->create a new repository on the command line:

echo "# DHBW" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/cai-pi-rinha/DHBW.git
git push -u origin master

->command to compile project:
1) add path of g++ compiler to system variable "path" - seperated from the other paths by a semicolon ';'
	~> path is something like: "C:\Program Files (x86)\CodeBlocks\MinGW\bin"
2) in cmd type: "g++ -o outputfilename main.cpp"	// -o to create executable and outputfilename as the name of the *.exe that is going to be created
