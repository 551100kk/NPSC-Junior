for f in *.in
do
  echo "from $f to ${f/in/ans}"
  ./../../submissions/accepted/a.out < "$f" > "${f/in/ans}"
done
