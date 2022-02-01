# $@ Contiene el target
# $< Contiene las dependencias del target

MY_BRANCH	=	calvino_franco
COMMIT		=	Actualizacion

#Antes de cambiar de rama, sobo al repositorio todo lo de mi commit para no perder los cambios hechos
ToMaster: update
	git checkout master
	
ToMyBranch:
	git checkout $(MY_BRANCH)

update:
	git add alumnos/$(MY_BRANCH)
	git commit -m "$(COMMIT)"
	git push origin $(MY_BRANCH)
	
PullFromOrigin:
	git pull origin master
	
ShowCurrentBranch:
	git branch -a

