#include "Dispatcher.h"
Dispatcher::Dispatcher() {
	// TO BE CONTINUED . . .
}
Dispatcher::Dispatcher(createCommand _create, deleteCommand _delete, updateCommand _update, showCommand _show, optimizeCommand _optimize, searchCommand _search, exitCommand _exit) {
	this->create_command = _create;
	this->delete_command = _delete;
	this->update_command = _update;
	this->show_command = _show;
	this->optimize_command = _optimize;
	this->search_command = _search;
	this->exit_command = _exit;
}
void Dispatcher::createAttribute() {
	create_command.execute();
}
void Dispatcher::deleteAttribute() {
	delete_command.execute();
}
void Dispatcher::updateAttribute() {
	update_command.execute();
}
void Dispatcher::showAttribute() {
	show_command.execute();
}
void Dispatcher::opitmizeAttribute() {
	optimize_command.execute();
}
void Dispatcher::exitProgram() {
	exit_command.execute();
}