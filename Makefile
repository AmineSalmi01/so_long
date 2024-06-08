all :
	@make -C Mandatory
clean :
	@make clean -C Mandatory

fclean : clean
	@make fclean -C Mandatory

re : fclean all

.PHONY: all clean