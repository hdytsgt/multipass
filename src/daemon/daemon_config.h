/*
 * Copyright (C) 2017 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alberto Aguirre <alberto.aguirre@canonical.com>
 *
 */

#ifndef MULTIPASS_DAEMON_CONFIG_H
#define MULTIPASS_DAEMON_CONFIG_H

#include <multipass/path.h>
#include <multipass/rpc/multipass.grpc.pb.h>

#include <multipass/virtual_machine_factory.h>
#include <multipass/virtual_machine_execute.h>
#include <multipass/vm_image_host.h>
#include <multipass/vm_image_vault.h>
#include <multipass/name_generator.h>
#include <multipass/ssh_key.h>
#include <multipass/url_downloader.h>

#include <memory>

namespace multipass
{

struct DaemonConfig
{
    const std::unique_ptr<URLDownloader> url_downloader;
    const std::unique_ptr<VirtualMachineFactory> factory;
    const std::unique_ptr<VMImageHost> image_host;
    const std::unique_ptr<VMImageVault> vault;
    const std::unique_ptr<NameGenerator> name_generator;
    const std::unique_ptr<VirtualMachineExecute> vm_execute;
    const std::unique_ptr<SshPubKey> ssh_key;
    const multipass::Path cache_directory;
    const std::string server_address;
};

struct DaemonConfigBuilder
{
    std::unique_ptr<URLDownloader> url_downloader;
    std::unique_ptr<VirtualMachineFactory> factory;
    std::unique_ptr<VMImageHost> image_host;
    std::unique_ptr<VMImageVault> vault;
    std::unique_ptr<NameGenerator> name_generator;
    std::unique_ptr<VirtualMachineExecute> vm_execute;
    std::unique_ptr<SshPubKey> ssh_key;
    multipass::Path cache_directory;
    std::string server_address;

    std::unique_ptr<const DaemonConfig> build();
};
}

#endif // MULTIPASS_DAEMON_CONFIG_H
