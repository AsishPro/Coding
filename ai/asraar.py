import random

NUM_SERVERS = 100
MAX_NUM_JOBS = 1000

class Job:
    def _init_(self, processing_time):
        self.processing_time = processing_time

class Server:
    def _init_(self):
        self.capacity = 50
        self.queue = []
        self.queue_size = 0

def initialize_servers_and_jobs(servers, jobs, num_jobs):
    for _ in range(NUM_SERVERS):
        servers.append(Server())

    for _ in range(num_jobs):
        jobs.append(Job(10))  # Fixed processing time of 10 for all jobs

def submit_jobs_to_all_servers(jobs, servers):
    for job in jobs:
        min_capacity_server = max(range(NUM_SERVERS), key=lambda i: (servers[i].capacity, servers[i].queue_size))
        servers[min_capacity_server].queue.append(job)
        servers[min_capacity_server].queue_size += 1
        servers[min_capacity_server].capacity -= 1

def process_jobs(servers):
    migrations = 0
    for server in servers:
        for job in server.queue[:]:
            if server.capacity >= job.processing_time:
                server.capacity -= job.processing_time
                server.queue.remove(job)
            else:
                for other_server in servers:
                    if other_server.capacity >= job.processing_time:
                        other_server.queue.append(job)
                        other_server.queue_size += 1
                        other_server.capacity -= job.processing_time
                        migrations += 1
                        server.queue.remove(job)
                        break
    return migrations

num_jobs = int(input("Enter the number of jobs: "))
servers = []
jobs = []

initialize_servers_and_jobs(servers, jobs, num_jobs)
submit_jobs_to_all_servers(jobs, servers)
total_migrations = process_jobs(servers)
print(f"Total number of migrations: {total_migrations}")