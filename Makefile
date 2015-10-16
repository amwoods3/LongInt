COMMIT_MESSAGE?=""

mac:
	clang++ -o factorial *.cpp
run:
	./factorial
add:
	git add . -A
commit:
	git commit -m "$(COMMIT_MESSAGE)"
push: add commit
	git push