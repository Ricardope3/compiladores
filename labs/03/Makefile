all :
	lex lexic_analyzer.l
	gcc lex.yy.c -o lexical_scan -lfl
	python3 code_generator.py > example.ac
	./lexical_scan example.ac
clean:
	rm lex.yy.c ./lexical_scan lex.out example.ac