


void signal_catch(int sig)
{
	char* arSigInfo[]={"other", "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGTRAP", 
		"SIGABRT/SIGIOT", "SIGBUS", "SIGFPE", "SIGKILL", "SIGUSR", 
		"SIGSEGV", "SIGUSR", "SIGPIPE", "SIGALRM", "SIGTERM", "SIGSTKFLT", 
		"SIGCHLD", "SIGCONT", "SIGSTOP", "SIGTSTP", "SIGTTIN", "SIGTTOU", 
		"SIGURG", "SIGXCPU", "SIGXFSZ", "SIGVTALRM", "SIGPROF", "SIGWINCH", 
		"SIGIO", "SIGPWR", "SIGSYS"};
	debug_output_file("WhiteList:Recive signal:%s\n", arSigInfo[sig]);
	switch(sig)
	{
		case SIGINT:
		case SIGHUP:
		case SIGQUIT:
		case SIGILL:
		case SIGSEGV:
		case SIGPWR:
		case SIGSTKFLT:
		case SIGFPE:
			debug_output_file("WhiteList:Recive signal:%s\n", arSigInfo[sig]);
			exit(0);
			break;
		default:
			break;
	}
}

void SetupSignal(void)
{
	struct sigaction act;
	act.sa_handler = signal_catch;
	act.sa_flags   = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGHUP, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	sigaction(SIGILL, &act, NULL);
	sigaction(SIGTRAP, &act, NULL);
	sigaction(SIGABRT, &act, NULL);
	sigaction(SIGTRAP, &act, NULL);
	sigaction(SIGBUS, &act, NULL);
	sigaction(SIGFPE, &act, NULL);
	sigaction(SIGKILL, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGSEGV, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGPIPE, &act, NULL);
	sigaction(SIGALRM, &act, NULL);
	sigaction(SIGTERM, &act, NULL);
	sigaction(SIGSTKFLT, &act, NULL);
	sigaction(SIGCHLD, &act, NULL);
	sigaction(SIGCONT, &act, NULL);
	sigaction(SIGSTOP, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);
	sigaction(SIGTTIN, &act, NULL);
	sigaction(SIGTTOU, &act, NULL);
	sigaction(SIGURG, &act, NULL);
	sigaction(SIGXCPU, &act, NULL);
	sigaction(SIGXFSZ, &act, NULL);
	sigaction(SIGVTALRM, &act, NULL);
	sigaction(SIGPROF, &act, NULL);
	sigaction(SIGWINCH, &act, NULL);
	sigaction(SIGIO, &act, NULL);
	sigaction(SIGPWR, &act, NULL);
	sigaction(SIGSYS, &act, NULL);
}

