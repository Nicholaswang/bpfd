// Test-program for reading time_in_state

#include "libbpf.h"

using namespace android::bpf;

int main(void) {
	int ret, prog_fd, map_fd;

	ret = load_prog("timeinstate/bpf_kern.o");
	printf("bpf prog loaded... %d\n", ret);

	prog_fd = bpf_obj_get("/sys/fs/bpf/prog_bpf_kern_tracepoint_sched_sched_switch");
	ret = bpf_attach_tracepoint(prog_fd, "sched", "sched_switch");
	printf("tp sched sw attach %d\n", ret);

	prog_fd = bpf_obj_get("/sys/fs/bpf/prog_bpf_kern_tracepoint_power_cpu_frequency");
	ret = bpf_attach_tracepoint(prog_fd, "power", "cpu_frequency");
	printf("tp power attach %d\n", ret);

	return 0;

	BpfMapPerCpu<int, int> m(2);

        const auto iterf = [](const int& key,
			      const std::vector<int>& vals,
			      const BpfMap<int, int>& map) {
		printf("test\n");

		return 0;
	};

        m.iterateWithValues(iterf);
}