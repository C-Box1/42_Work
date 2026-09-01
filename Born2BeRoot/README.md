This project was completed as part of the 42 curriculum by *`csahyoun`*.

It consists of installing and configuring a secure virtual machine running  **Debian** , following strict system administration rules.

## Description

This project implements a minimal (non-graphical) Linux server inside a VM for the Born2beRoot exercise. Its goals are:

* Build and configure a secure VM with encrypted LVM partitions.
* Enforce a strict password and sudo policy.
* Run an SSH server on a nonstandard port.
* Configure a firewall (UFW on Debian, `firewalld` on Rocky).
* Provide a `monitoring.sh` script that broadcasts system stats at boot and every 10 minutes.

# Operating System

## Debian

Debian was chosen because:

* It is stable and widely used in production environments.
* It has strong package management via `apt`.
* It uses AppArmor by default, which is easier to configure than SELinux.
* It is recommended for beginners in system administration.

Minimal installation was performed (no graphical environment).

## Instructions

### 1) How to boot the VM

* VM engine used: `VirtualBox`. Add your VM disk image to your virtualization software and attach the installation ISO.

### 2) Installation notes (example CLI steps / highlights)

* Partition manually in the installer:
  * create `/boot` (not encrypted), create LVM physical volume on the remaining disk, create encrypted LUKS container, create LVs inside LUKS for `root`, `home`, `swap`, `var`, `srv`, `tmp`, `var--log`.
* Install base system without any GUI packages.
* Install `openssh-server` and configure to listen on port `4242`.
  * Edit `/etc/ssh/sshd_config`:
    ```
    Port 4242
    PermitRootLogin no
    ```
  * Reload SSH: `sudo service ssh restart`
* Configure sudo: create group `sudo`, adjust `/etc/sudoers.d/` with logging, TTY enabled, attempt limit = 3, custom wrong-password message.
* Configure password policy with PAM and `chage`/`pam_pwquality` per requirements.
* Enable AppArmor (Debian).

### 3) Firewall

* Debian (UFW):

  ```bash
  sudo apt install ufw
  sudo ufw enable
  sudo ufw allow 4242
  sudo ufw status
  ```

### 4) monitoring.sh

Place `monitoring.sh` in `/usr/local/bin/monitoring.sh`, make executable:

<pre class="overflow-visible! px-0!" data-start="3753" data-end="3802"><div class="relative w-full my-4"><div class=""><div class="relative"><div class="h-full min-h-0 min-w-0"><div class="h-full min-h-0 min-w-0"><div class="border border-token-border-light border-radius-3xl corner-superellipse/1.1 rounded-3xl"><div class="h-full w-full border-radius-3xl bg-token-bg-elevated-secondary corner-superellipse/1.1 overflow-clip rounded-3xl lxnfua_clipPathFallback"><div class="pointer-events-none absolute inset-x-4 top-12 bottom-4"><div class="pointer-events-none sticky z-40 shrink-0 z-1!"><div class="sticky bg-token-border-light"></div></div></div><div class=""><div class="relative z-0 flex max-w-full"><div id="code-block-viewer" dir="ltr" class="q9tKkq_viewer cm-editor z-10 light:cm-light dark:cm-light flex h-full w-full flex-col items-stretch ͼs ͼ16"><div class="cm-scroller"><div class="cm-content q9tKkq_readonly"><span class="ͼ10">chmod</span><span></span><span class="ͼv">+</span><span>x /usr/local/bin/monitoring.sh</span></div></div></div></div></div></div></div></div></div><div class=""><div class=""></div></div></div></div></div></pre>

Add a cronjob or systemd timer to run at boot and every 10 minutes:

* Example `cron` line for root: `@reboot /usr/local/bin/monitoring.sh` and `*/10 * * * * /usr/local/bin/monitoring.sh`

(Implement script according to the project spec — it must broadcast the listed metrics using `wall`.)

### 5) Sudo logging & restrictions

* Ensure sudo logs inputs/outputs to `/var/log/sudo`.
* Restrict `secure_path` in `/etc/sudoers` to:
  ```
  Defaults security_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
  ```
* Set custom incorrect password message using sudoers `badpass_message`.

### 6) Final actions

* Change all account passwords after configuration.
* Generate `signature.txt` at repo root: add SHA1 of your virtual disk (`.vdi` or `.qcow2`) as instructed in the subject. Example host commands:
  * Linux: `shasum Born2beRoot.vdi`

## Resources

* Youtube tutorial, a step-by-step video tutorial was used to better understand the Debian installation process, LVM partitioning, and system configuration.
* A public GitHub repository was consulted as a reference to compare configuration structure, file organization, and general project flow.
* AI assistance was used **only** for:
  * Understanding and clearly defining the differences between:
    * Debian vs Rocky
    * apt vs aptitude
    * AppArmor vs SELinux
    * UFW vs firewalld
    * VirtualBox vs UTM

## Technical comparaison:

### Debian vs Rocky Linux

Debian:

* Community-driven
* Very stable
* Slower updates
* Uses `apt`
* Uses AppArmor by default
* Popular for servers

Rocky Linux:

* Enterprise-focused
* RHEL-compatible (Red Hat ecosystem)
* Used in corporate infrastructure
* Uses `dnf`
* Uses SELinux by default

### AppArmor vs SELinux

AppArmor (Debian default):

* Path-based
* Rules are written per program
* Easier to configure
* Less complex

SELinux (Rocky default):

* Label-based
* Every file and process has a security context
* Very powerful
* Much more complex

### UFW vs firewalld

UFW:

* Very simple
* Good for small servers
* Easy commands like:

  `ufw allow 4242`

firewalld:

* Uses zones (public, internal, etc.)
* Dynamic rule management
* More enterprise-oriented

### VirtualBox vs UTM

VirtualBox:

* Works well on Windows/Linux
* Designed for x86_64 CPUs

UTM:

* Built for macOS
* Works on Apple Silicon (M1/M2)
* Uses QEMU internally
