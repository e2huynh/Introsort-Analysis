target:
	g++ ./cpp/main.cpp -o ./cpp/main
	./cpp/main
	python ./pyScripts/csvToExcel.py