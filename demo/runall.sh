# !/bin/shell/
# Run all tests scripts
# v.1.0.0
for file in ./*.out
do
  ./"$file"
done
