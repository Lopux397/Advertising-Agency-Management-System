set "msg=%*"
set "msg=%msg:"=%"
git add .
git commit -m "%msg%"
git push