
target:
	-mkdir images
	python3 Chess.py
animation:
	convert images/*.png chess.gif
convert:
	jupyter nbconvert --to python Chess.ipynb
clean:
	-rm images/*png
