from setuptools import find_packages
from setuptools import setup

setup(
    name='armos_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('armos_interfaces', 'armos_interfaces.*')),
)
